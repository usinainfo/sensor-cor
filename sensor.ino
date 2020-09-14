// Projeto Arduino Sensor de Cor RGB

#define pinoS0 4   // Define o pino pinoS0 como pino Digital 4
#define pinoS1 5   // Define o pino pinoS1 como pino Digital 5
#define pinoS2 6   // Define o pino pinoS2 como pino Digital 6
#define pinoS3 7   // Define o pino pinoS3 como pino Digital 7
#define pinoOut 8  // Define o pino pinoOut como pino Digital 8

#define azul 9        // Define LED azul como pino digital 9
#define verde 10      // Define LED verde como pino digital 10
#define vermelho 11   // Define LED vermelho como pino digital 11

void setup() {
pinMode(pinoS0, OUTPUT);    // Configula pinoS0 como saída
pinMode(pinoS1, OUTPUT);    // Configula pinoS1 como saída
pinMode(pinoS2, OUTPUT);    // Configula pinoS2 como saída
pinMode(pinoS3, OUTPUT);    // Configula pinoS3 como saída

pinMode(azul, OUTPUT);      // Configula LED azul como saída
pinMode(verde, OUTPUT);     // Configula LED verde como saída
pinMode(vermelho, OUTPUT);  // Configula LED vermelho como saída

pinMode(pinoOut, INPUT);    // Configura sensorOut como entrada

// Configura a escala de frequência para 20%
digitalWrite(pinoS0,HIGH);
digitalWrite(pinoS1,LOW);
}

void loop() {
// Armazena as frequências lida pelos fotodiodos
int ValorVermelho, ValorVerde, ValorAzul;

// Configura a leitura para os fotodiodos Red (Vermelho)
digitalWrite(pinoS2,LOW);
digitalWrite(pinoS3,LOW);
delay(50);

// Lê a frequencia de saída do fotodiodo vermelho
ValorVermelho = pulseIn(pinoOut, LOW);

// Configura a leitura para os fotodiodos Green (Verde)
digitalWrite(pinoS2,HIGH);
digitalWrite(pinoS3,HIGH);
delay(50);

// Lê a frequencia de saída do fotodiodo verde
ValorVerde = pulseIn(pinoOut, LOW);

// Configura a leitura para os fotodiodos Blue (Azul)
digitalWrite(pinoS2,LOW);
digitalWrite(pinoS3,HIGH);
delay(50);

// Lê a frequencia de saída do fotodiodo azul
ValorAzul = pulseIn(pinoOut, LOW);

// Analisa se a menor frequencia é vermelha e liga o led vermelho
if (ValorVermelho < ValorVerde && ValorVermelho < ValorAzul) {

analogWrite(vermelho, 255);
analogWrite(verde, 0);
analogWrite(azul, 0);
}

// Analisa se a menor frequencia é verde e liga o led verde
if (ValorVerde < ValorVermelho && ValorVerde < ValorAzul) {
analogWrite(verde, 255);
analogWrite(vermelho, 0);
analogWrite(azul, 0);
}

// Analisa se a menor frequencia é azul e liga o led azul
if (ValorAzul < ValorVermelho && ValorAzul < ValorVerde) {
analogWrite(azul, 255);
analogWrite(vermelho, 0);
analogWrite(verde, 0);
}

delay(1000);  // Aguarda 1 segundo e reinicia leitura
}
