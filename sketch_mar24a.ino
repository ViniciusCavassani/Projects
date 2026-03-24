int led=2;
int botao1=5;
int botao2=4;

void setup() 
{
  pinMode(led, OUTPUT);
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
}
void loop() 
{
 if (digitalRead(botao1)==1)
{
digitalWrite(led, HIGH);
}
if (digitalRead(botao2)==1)
{
digitalWrite(led, LOW);
}
}
