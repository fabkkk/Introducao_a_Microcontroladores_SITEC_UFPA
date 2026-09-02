const int PIR = 23;
const int LED = 21;

void setup()
{
    pinMode(PIR, INPUT);
    pinMode(LED, OUTPUT);
}

void loop()
{
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
