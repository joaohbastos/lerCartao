🪪 Leitor de Cartão RFID — Arduino
Este projeto utiliza um módulo de leitura RFID para identificar cartões ou tags e exibir o código lido através da Serial Monitor. É ideal para sistemas de identificação, controle de acesso ou automação.

🚀 Funcionalidades
Lê o UID (código único) de cartões ou tags RFID.

Exibe o UID no Serial Monitor.

Pode ser adaptado para sistemas de controle de acesso ou identificação automática.

🛠️ Componentes necessários
1x Arduino (UNO, Mega, etc.)

1x Módulo Leitor RFID (MFRC522 ou PN532)

Tags ou cartões RFID (13.56 MHz)

Jumpers

Protoboard (opcional)

🔌 Esquema de ligação (para MFRC522 via SPI)
Módulo RFID	Pino Arduino
SDA (SS)	10
SCK	13
MOSI	11
MISO	12
IRQ	Não conectado
GND	GND
RST	9
3.3V	3.3V

⚠️ Importante: O MFRC522 deve ser alimentado com 3.3V!

💻 Código
O código está no arquivo: lerCartao.ino.

Principais pontos:

Inicializa a comunicação com o módulo RFID.

Aguarda aproximação de um cartão ou tag.

Lê e exibe o UID no Serial Monitor.

⚙️ Como usar
Monte o circuito conforme o esquema acima.

Abra o Arduino IDE.

Instale a biblioteca MFRC522 ou PN532, conforme o seu módulo.

Carregue o código lerCartao.ino.

Selecione a porta e o modelo corretos do seu Arduino.

Abra o Serial Monitor e ajuste a velocidade conforme configurado no código (geralmente 9600 bps).

Aproximar um cartão ou tag do leitor e observar o UID exibido no monitor.

📝 Configurações importantes
Ajuste os pinos no código se estiver usando um módulo ou conexão diferente (por exemplo, I2C).

Confirme a tensão de alimentação:
→ MFRC522: 3.3V
→ PN532: depende do modo de operação.

📄 Licença
Este projeto é de livre uso para fins educacionais e pessoais.

ℹ️ Observações
Pode ser facilmente adaptado para acionar relés, LEDs ou dispositivos de bloqueio após leitura do cartão.

Para maior segurança, compare o UID lido com um banco de dados ou uma lista autorizada no código.
