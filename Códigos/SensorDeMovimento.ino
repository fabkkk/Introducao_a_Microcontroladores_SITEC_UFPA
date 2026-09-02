// primeiramente definimos os pinos para o LED e para o sensor
const int PIR = 23;
const int LED = 21;

// definindo as funções de cada pino
void setup()
{
    pinMode(PIR, INPUT);
    pinMode(LED, OUTPUT);
}

void loop()
{
    // criamos uma variável para armazenar a leitura do sensor
    int movimento = digitalRead(PIR);

    if (movimento == HIGH)
    {
        digitalWrite(LED, HIGH);
    }
    else
    {
        digitalWrite(LED, LOW);
    }
}
