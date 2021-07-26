// Declaração dos pinos dos componentes
const int pinoLDR = A0;
const int pinoBuzzer = 9;
const int pinoBotao = 8;
const int pinLED = 7;
const int pinLED2 = 6;

// Variáveis gerais
int leituraLDR = 0;
int leituraBotao;

void setup()
{
  // Configura os pinos
  pinMode(pinoLDR, INPUT);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinLED, OUTPUT);
  pinMode(pinLED2, OUTPUT);
  pinMode(pinoBotao, INPUT_PULLUP);
}

void loop()
{
  // le o valor de tensão no pino do LDR
  leituraLDR = analogRead(pinoLDR);
  // le o estado do botao
  leituraBotao = digitalRead(pinoBotao);

  digitalWrite(pinLED2, HIGH);

  // Se existir um obstáculo
  if (leituraLDR <= 512)
  {
    tone(pinoBuzzer, 1000); // aciona o buzzer
    digitalWrite(pinLED2, LOW);
    digitalWrite(pinLED, HIGH);
    delay(100);
    digitalWrite(pinLED, LOW);
  }
  else if (leituraBotao == LOW)
  {                     // senão e o botão estiver pressionado
    noTone(pinoBuzzer); // desliga o buzzer

  }


  delay(100); // aguarda 100 milissegundos para uma nova leitura
}