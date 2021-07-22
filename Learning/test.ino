#define t 200
#define led 13
#define led_ON digitalWrite (led,HIGH);
#define led_OFF digitalWrite (led,LOW);
void setup()
{
  pinMode (led, OUTPUT);
}
void loop ()
{
  led_ON;
  delay (t);
  led_OFF;
  delay (t);
}