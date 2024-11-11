# FECAP - Fundação de Comércio Álvares Penteado

<p align="center">
<a href= "https://www.fecap.br/"><img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRhZPrRa89Kma0ZZogxm0pi-tCn_TLKeHGVxywp-LXAFGR3B1DPouAJYHgKZGV0XTEf4AE&usqp=CAU" alt="FECAP - Fundação de Comércio Álvares Penteado" border="0"></a>
</p>

# Sistema de Socorro Automático

## S.S.A

## Integrantes: <a href="https://www.linkedin.com/in/caio-gomes-889178248/">Caio dos Santos Gomes</a>, <a href="https://www.linkedin.com/in/eduardo-sturm-599a45223/">Eduardo Sturm</a>, <a href="">Eduardo Stradiotto</a>, <a href="">João Pedro Holanda</a>.

## Professores Orientadores: <a href="https://www.linkedin.com/in/victorbarq/">Victor Bruno</a>.
 
<p align="center">
<img src="imagens/ft120.jpeg" alt="NOME DO JOGO" border="0">
  Projeto desenvolvido por: <a href="https://www.linkedin.com/in/caio-gomes-889178248/">Caio dos Santos Gomes</a>, <a href="https://www.linkedin.com/in/eduardo-sturm-599a45223/">Eduardo Sturm</a>, <a href="">Eduardo Stradiotto</a> e <a href="">João Pedro Holanda</a>.

</p>


DESCRIÇÃO DO PROJETO
.
<br><br>
O projeto consiste em um capacete inteligente integrado com um sistema de Internet das Coisas (IoT) que tem como objetivo proporcionar segurança e agilidade no atendimento a acidentes, especialmente em atividades de risco, como motociclismo, ciclismo ou construção civil. O capacete é equipado com sensores e dispositivos conectados à rede, permitindo a detecção de quedas ou impactos significativos.
<br><br>
## 🛠 Estrutura de pastas

-Raiz<br>
|<br>
|-->documentos<br>
  &emsp;|Documentação.docx<br>
|-->imagens<br>
|-->src<br>
  &emsp;|-->Backend<br>
|readme.md<br>

A pasta raiz contem dois arquivos que devem ser alterados:

<b>README.MD</b>: Arquivo que serve como guia e explicação geral sobre seu projeto. O mesmo que você está lendo agora.

<b>documentos</b>: Toda a documentação estará nesta pasta.

<b>imagens</b>: Imagens do sistema.

## 🛠 Equipamentos utilizados

🛠 Hardware
<br>•ESP32</br>
<br>•Sensor MPU 6050</br>
<br>•Sensor de Vibração SW-420</br>
<br>•Protobord</br>
<br>•Jumpers Macho e Fêmea.</br>
<br>•Componentes.</br>

🛠 Software 
<bR>•Arduino IDE</br>
<bR>•Telegram</br>

## 🛠 Instalação Telegram 

Este guia fornece instruções para instalar o **Telegram** em diferentes dispositivos, incluindo smartphones (Android e iOS), computadores (Windows, macOS e Linux) e na versão web.

## 1. Instalar Telegram no Smartphone

### No Android:
1. Abra a **Google Play Store** no seu dispositivo.
2. Na barra de pesquisa, digite **"Telegram"** e selecione o aplicativo oficial (geralmente o primeiro resultado).
3. Toque no botão **Instalar**.
4. Após a instalação, abra o aplicativo.
5. **Crie uma conta** ou entre com sua conta existente usando o número de telefone.
6. Siga as instruções para configurar seu perfil e começar a usar o Telegram.

### No iOS (iPhone):
1. Abra a **App Store** no seu iPhone.
2. Na barra de pesquisa, digite **"Telegram"** e selecione o aplicativo oficial.
3. Toque no botão **Obter** para iniciar o download e a instalação.
4. Após a instalação, abra o aplicativo.
5. **Crie uma conta** ou entre com sua conta existente usando o número de telefone.
6. Configure seu perfil e pronto, você está pronto para usar o Telegram.

## 2. Instalar Telegram no Computador

### No Windows (PC):
1. Acesse o [site oficial do Telegram](https://desktop.telegram.org/).
2. Clique no botão **"Get Telegram for Windows"** (Obter Telegram para Windows).
3. Após o download, abra o arquivo executável `.exe` para iniciar a instalação.
4. Siga as instruções do assistente de instalação.
5. Após a instalação, abra o Telegram no seu PC e entre com o número de telefone para sincronizar com sua conta.

### No macOS:
1. Acesse o [site oficial do Telegram](https://desktop.telegram.org/) ou baixe o Telegram diretamente na **Mac App Store**.
2. Caso opte pelo site, clique em **"Get Telegram for macOS"**.
3. Após o download, abra o arquivo `.dmg` e arraste o Telegram para a pasta **Aplicativos**.
4. Abra o Telegram a partir da pasta **Aplicativos** e faça login com seu número de telefone.

### No Linux:
1. Acesse o [site oficial do Telegram](https://desktop.telegram.org/).
2. Escolha a versão para **Linux** e baixe o arquivo correspondente ao seu sistema.
3. Descompacte o arquivo em seu diretório desejado e siga as instruções específicas para a instalação (geralmente usando o terminal).

## 3. Usar Telegram na Web

Se você não quer instalar o Telegram no seu dispositivo, você pode usar a versão web diretamente no seu navegador:

1. Acesse [https://web.telegram.org](https://web.telegram.org).
2. Faça login com seu número de telefone.
3. Agora você pode usar o Telegram diretamente no seu navegador.

## 4. Telegram em Outros Dispositivos

O Telegram também está disponível para **tablets** e **smart TVs**. Basta procurar o aplicativo na loja correspondente (Google Play Store ou App Store) e seguir as instruções para instalação.

## Dicas após a instalação:
- **Sincronização entre dispositivos**: O Telegram sincroniza automaticamente as suas mensagens entre todos os dispositivos em que você 




## 🛠 Instalação Arduino IDE
<br>•Instale o Arduino IDE a partir no site: https://www.arduino.cc/en/software</br>
<br>• Abra o Arduino IDE após ser instalado.</br>

⚙ Configuração do Arduino IDE para ESP32:
<br>• Baixe as bibliotecas Sketch -> Include Library -> Menage Libraries -> pesquise por Blynk e instale.</br>
<br>• Instale o drive CP210x Universal Windows Driver no site Silicon Labs</br>
<br>• No Arduino IDE, vá em File > Preferences.</br>
<br>• Adicione a URL a seguir ao campo "Additional Board Manager URLs"
```sh
https://dl.espressif.com/dl/package_esp32_index.json
```
<br>• Vá em Tools > Board > Boards Manager, procure por "esp32" e clique em instalar.</br>
<br>• Conecte o ESP32 ao Blynk</br>

## 🗃 Histórico de lançamentos

A cada atualização os detalhes devem ser lançados aqui.

* 0.1.1 - 10/10/2024
    * Planejamento do projeto e aquisição dos materiais
* 0.1.2 - 23/10/2024
    * Inicio da construção do código e do circuito 
* 0.1.3 - 09/11/2024
    * Integração do Esp32 com o Telegram
 * 0.1.4 - 13/11/2024
    * Organização do github e fichas do projeto
 * 0.1.5 - 16/11/2024
    *Últimos testes do sensor e aplicativo


## 📋 Licença/License
<p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/2024-2-NADS1/Projeto4/tree/main">S.S.A</a> is licensed under <a href="https://creativecommons.org/licenses/by/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">CC BY 4.0<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1" alt=""><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1" alt=""></a></p>


## 🎓 Referências

Aqui estão as referências usadas no projeto.

1. 
