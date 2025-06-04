🪪 **Leitor de Cartão RFID com PN532 — Arduino
#Este projeto utiliza um módulo de leitura RFID PN532 para identificar cartões ou tags RFID/NFC e exibir o código lido através do Serial Monitor. Ideal para sistemas de identificação, controle de acesso ou automação.**

🚀 Funcionalidades
Lê o UID (código único) de cartões ou tags RFID/NFC.

Exibe o UID no Serial Monitor.

Compatível com diversas tags NFC de 13.56 MHz.

Pode ser adaptado para sistemas de controle de acesso.

🛠️ Componentes necessários
1x Arduino (UNO, Mega, etc.)

1x Módulo Leitor RFID PN532

Tags ou cartões RFID/NFC (13.56 MHz)

Jumpers

Protoboard (opcional)

🔌 Esquema de ligação (modo I2C)

PN532	Pino Arduino

Arduino | PN532
SDA	      SDA
SCL	      SCL
IRQ	       2
RSTO       3
VCC	       5V
GND	      GND

🔌 Esquema de ligação (modo I2C)

Arduino | Display
SDA       SDA
SCL       SCL
VCC       VCC
GND       GND

⚠️ Importante: O PN532 pode operar em I2C, SPI ou UART. Este projeto está configurado para I2C.

💻 Código
O código está no arquivo: lerCartao.ino.

Principais pontos:

Inicializa a comunicação com o PN532 via I2C.

Aguarda aproximação de um cartão ou tag.

Lê e exibe o UID no Serial Monitor.

⚙️ Como usar
Monte o circuito conforme o esquema acima.

Abra o Arduino IDE.

Instale a biblioteca Adafruit PN532:

Acesse: Sketch → Include Library → Manage Libraries...

Busque por "Adafruit PN532" e instale.

Carregue o código lerCartao.ino.

Selecione a porta e o modelo corretos do seu Arduino.

Abra o Serial Monitor e ajuste a velocidade conforme configurado no código (geralmente 9600 bps).

Aproximar um cartão ou tag do leitor e observar o UID exibido no monitor.

📝 Configurações importantes
Endereço I2C padrão do PN532: 0x24 ou 0x48 dependendo da versão do módulo e dos jumpers.
→ Verifique no datasheet do seu módulo!

Se for usar SPI ou UART, adapte o código e a ligação.

📄 Licença
Este projeto é de livre uso para fins educacionais e pessoais.

ℹ️ Observações
Pode ser facilmente adaptado para acionar relés, LEDs ou dispositivos de bloqueio após leitura do cartão.

Para maior segurança, compare o UID lido com uma lista autorizada no código.
