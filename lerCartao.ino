#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_PN532.h>

// Inicialização do LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Inicialização do leitor PN532 via I2C
Adafruit_PN532 nfc(2, 3, &Wire);

// Listas de UIDs para cada cor (exemplo, substitua pelos reais)
String uidsCinza[] = {"439A2000", "4C9D1F00", "66B91600", "24352000", "F2531F00", "6BCF1400", "360C1200", "9CCF1400", "4DD7200", "13EB1F00", "BD411000", "2A691100", "B4311000", "EC292100", "553C2000", "2CAB0F00", "B6381000", "675F2200", "BCB51500"};
String uidsAmarelo[] = {"CB021000", "D3E5D427", "23661400", "61D51F00", "91E44100", "45E90F00", "BD1E1000", "BE4B2100", "23CDAE27", "5E081100"};
String uidsVermelho[] = {"55031000", "BD341000", "E1BD1500", "B7C00F00", "76041200", "92E42000", "73172000", "03101700", "479A1100", "43E3D2E3", "FC482000", "8C902100", "73202100", "117C2000", "D9502100", "5C621400", "5C621400", "CC1B2000", "913E2000", "F5A62100", "CE802000"};

// Função para verificar se UID está na lista
bool estaNaLista(String uid, String lista[], int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    if (lista[i] == uid) {
      return true;
    }
  }
  return false;
}

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  nfc.begin();
  uint32_t versiondata = nfc.getFirmwareVersion();
  if (!versiondata) {
    Serial.println("Não foi possível encontrar o PN532");
    while (1);
  }
  nfc.SAMConfig();

  lcd.print("Aproxime RFID");
}

void loop() {
  uint8_t uid[7];
  uint8_t uidLength;

  if (nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength)) {

    // Converter UID para String
    String uidString = "";
    for (uint8_t i = 0; i < uidLength; i++) {
      if (uid[i] < 0x10) uidString += "0";
      uidString += String(uid[i], HEX);
    }
    uidString.toUpperCase();

    Serial.print("UID detectado: ");
    Serial.println(uidString);

    int numeroAleatorio = 0;

    if (estaNaLista(uidString, uidsCinza, sizeof(uidsCinza) / sizeof(uidsCinza[0]))) {
      numeroAleatorio = random(0, 85);
    } else if (estaNaLista(uidString, uidsAmarelo, sizeof(uidsAmarelo) / sizeof(uidsAmarelo[0]))) {
      numeroAleatorio = random(85, 119);
    } else if (estaNaLista(uidString, uidsVermelho, sizeof(uidsVermelho) / sizeof(uidsVermelho[0]))) {
      numeroAleatorio = random(119, 156);
    } else {
      lcd.clear();
      lcd.print("UID nao cadastrado");
      delay(2000);
      lcd.clear();
      lcd.print("Aproxime RFID");
      return;
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Numero:");
    lcd.setCursor(0, 1);
    lcd.print(numeroAleatorio);

    delay(3000);

    lcd.clear();
    lcd.print("Aproxime RFID");
  }
}
