const int NUM_ELEMENTOS = 3;

const int pinLeds[NUM_ELEMENTOS]   = {25, 26, 27};

const int pinBotoes[NUM_ELEMENTOS] = {14, 12, 13};

#define MAX_RODADAS 10
int sequencia[MAX_RODADAS];
int rodadaAtual = 0;

void piscarLed(int indice, int tempo) {
  digitalWrite(pinLeds[indice], HIGH);
  delay(tempo);
  digitalWrite(pinLeds[indice], LOW);
  delay(150);
}

void tocarSequencia() {
  for (int i = 0; i < rodadaAtual; i++) {
    piscarLed(sequencia[i], 400);
  }
}

void efeitoErro() {
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < NUM_ELEMENTOS; i++) digitalWrite(pinLeds[i], HIGH);
    delay(200);
    for (int i = 0; i < NUM_ELEMENTOS; i++) digitalWrite(pinLeds[i], LOW);
    delay(200);
  }
}

void efeitoVitoria() {
  for (int i = 0; i < NUM_ELEMENTOS; i++) {
    digitalWrite(pinLeds[i], HIGH);
    delay(100);
  }
  delay(300);
  for (int i = 0; i < NUM_ELEMENTOS; i++) {
    digitalWrite(pinLeds[i], LOW);
  }
}

int aguardarBotao() {
  while (true) {
    for (int i = 0; i < NUM_ELEMENTOS; i++) {
      if (digitalRead(pinBotoes[i]) == LOW) { 
        piscarLed(i, 200);
        while (digitalRead(pinBotoes[i]) == LOW); 
        delay(50); 
        return i;
      }
    }
    delay(10);
  }
}

void setup() {
  for (int i = 0; i < NUM_ELEMENTOS; i++) {
    pinMode(pinLeds[i], OUTPUT);
    pinMode(pinBotoes[i], INPUT_PULLUP);
    digitalWrite(pinLeds[i], LOW);
  }
  
  // Semente aleatória usando um pino flutuante
  randomSeed(analogRead(34));
  
  efeitoVitoria();
  delay(1000);
}

void loop() {
  sequencia[rodadaAtual] = random(0, NUM_ELEMENTOS);
  rodadaAtual++;

  tocarSequencia();

  for (int i = 0; i < rodadaAtual; i++) {
    int botaoPressionado = aguardarBotao();
    
    if (botaoPressionado != sequencia[i]) {
      efeitoErro();
      rodadaAtual = 0; 
      delay(1500);
      return;
    }
  }

  delay(800);
}
