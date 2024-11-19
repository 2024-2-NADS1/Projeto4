#include <Wire.h>
#include <MPU6050.h>
#include <WiFi.h>
#include <HTTPClient.h>

// Configurações do Telegram
const char* ssid = "SEU_SSID"; // Nome da rede Wi-Fi
const char* password = "SUA_SENHA"; // Senha da rede Wi-Fi
String botToken = "SEU_TOKEN_DO_BOT"; // Token do bot fornecido pelo BotFather
String chatID = "SEU_CHAT_ID"; // Chat ID obtido no Telegram

MPU6050 mpu;

const int buzzerPin = 5; // Pino do buzzer no ESP32 (D5)
const int buttonPin = 25; // Pino do botão no ESP32

bool buzzerState = false; // Estado do buzzer (ligado/desligado)
unsigned long impactDetectedTime = 0; // Armazena o tempo da detecção do impacto
unsigned long buzzerStartTime = 0; // Armazena o tempo do início do buzzer
unsigned long buzzerInterval = 500; // Intervalo de apito (500ms)
unsigned long delayTime = 4000; // Tempo de espera de 4 segundos antes de começar a tocar o buzzer
bool isBuzzerActive = false; // Controle do estado ativo do buzzer
bool buttonPressed = false; // Verifica se o botão foi pressionado para parar o buzzer

// Variáveis para leitura do acelerômetro
int16_t ax, ay, az;
float totalAccel = 0;
float thresholdAccel = 1.5; // Definindo o limite de aceleração para detecção de movimento (ajustável)

void setup() {
    Serial.begin(115200);
    Wire.begin();
    mpu.initialize();
    pinMode(buzzerPin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP);

    if (mpu.testConnection()) {
        Serial.println("MPU6050 conectado.");
    } else {
        Serial.println("Erro de conexão no MPU6050.");
    }

    // Conexão com Wi-Fi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Conectando-se ao Wi-Fi...");
    }
    Serial.println("Conectado ao Wi-Fi!");

    // Envia uma mensagem inicial ao Telegram
    sendMessage("Bot do ESP32 está online!");
}

void loop() {
    detectImpact(); // Detecta movimentos significativos
    handleBuzzer(); // Controla o buzzer
    checkButtonPress(); // Verifica se o botão foi pressionado
    sendDataToSerialPlotter(); // Envia dados para o Serial Plotter
    delay(50); // Delay para reduzir a quantidade de leitura
}

// Função para detectar um movimento significativo baseado na aceleração
void detectImpact() {
    mpu.getAcceleration(&ax, &ay, &az);

    // Conversão para g's (gravitacional)
    float ax_g = ax / 16384.0;
    float ay_g = ay / 16384.0;
    float az_g = az / 16384.0;
    totalAccel = sqrt(ax_g * ax_g + ay_g * ay_g + az_g * az_g);

    // Exibe os valores de aceleração para o monitor serial (ajuda na calibração)
    Serial.print("ax: "); Serial.print(ax);
    Serial.print("\tay: "); Serial.print(ay);
    Serial.print("\taz: "); Serial.print(az);
    Serial.print("\ttotalAccel: "); Serial.println(totalAccel);

    // Verifica se houve um movimento significativo
    if (totalAccel >= thresholdAccel) { // Movimento detectado
        Serial.println("Movimento detectado!");
        impactDetectedTime = millis(); // Marca o tempo do impacto detectado
        isBuzzerActive = true; // Ativa o buzzer
        buzzerStartTime = millis(); // Inicia o tempo para o buzzer
        buttonPressed = false; // Reseta o estado do botão

        // Envia mensagem ao Telegram
        sendMessage("Impacto detectado! Aceleração total: " + String(totalAccel, 2) + " g");
    }
}

// Função para controlar o buzzer com apitos intercalados (500ms)
void handleBuzzer() {
    if (isBuzzerActive) {
        if (millis() - impactDetectedTime >= delayTime) { // Aguardar 4 segundos após o impacto
            if (millis() - buzzerStartTime >= buzzerInterval) { // Cada "pi" é emitido de 500ms em 500ms
                buzzerState = !buzzerState; // Alterna o estado do buzzer
                digitalWrite(buzzerPin, buzzerState ? HIGH : LOW); // Alterna o buzzer
                buzzerStartTime = millis(); // Reinicia o temporizador do buzzer
            }
        } else {
            digitalWrite(buzzerPin, LOW); // Desliga o buzzer até o intervalo de 4 segundos
        }
    } else {
        digitalWrite(buzzerPin, LOW); // Garante que o buzzer está desligado
    }
}

// Função para verificar o botão e desligar o buzzer se pressionado
void checkButtonPress() {
    if (digitalRead(buttonPin) == LOW) { // Botão pressionado
        buttonPressed = true; // Marca que o botão foi pressionado
        isBuzzerActive = false; // Desliga o buzzer quando o botão for pressionado
        digitalWrite(buzzerPin, LOW); // Desliga o buzzer imediatamente
        delay(200); // Debounce do botão para evitar múltiplos cliques
    }
}

// Envia dados para o Serial Plotter para monitoramento visual das leituras do MPU6050
void sendDataToSerialPlotter() {
    Serial.print("ax: "); Serial.print(ax);
    Serial.print("\tay: "); Serial.print(ay);
    Serial.print("\taz: "); Serial.print(az);
    Serial.print("\ttotalAccel: "); Serial.println(totalAccel);
}

// Função para enviar mensagens ao Telegram
void sendMessage(String message) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        String url = "https://api.telegram.org/bot" + botToken + "/sendMessage?chat_id=" + chatID + "&text=" + message;
        http.begin(url); // Inicia a requisição HTTP
        int httpCode = http.GET(); // Envia a requisição GET

        if (httpCode > 0) {
            Serial.println("Mensagem enviada com sucesso!");
        } else {
            Serial.println("Erro ao enviar mensagem.");
        }
        http.end(); // Finaliza a requisição
    } else {
        Serial.println("Falha na conexão Wi-Fi");
    }
}
