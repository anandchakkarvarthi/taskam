const byte A =10; // PIN FOR TOGGLING AS INPUT AND OUTPUT
void setup() 
{
  // TIMER 1 TO GENERATE CARRIER WAVES //
TCCR1A = 0;
TCCR1B = 0;
OCR1A = 2; // (16000000/(PRESCALER(8)*1MHz)-1)
TCCR1A =(1<<COM1B0); 
TCCR1B =(1<<WGM12); 
TCCR1B|=(1<<CS11);  
}
void loop()
{
DDRB  = (1<<2);
for (int i=0;i<=1000;i++)
{
  de(250);
}

DDRB = (0<<2);
for(int i=0;i<=1000;i++)
{
de(250);
}

}
void de(int n)
{
  // TIMER 0 TO GENERATE DELAY //
TCCR0A = 0;
TCCR0B = 0;
OCR0A = n;
TCCR0B = (1 << WGM02);
TCCR0B = (1 << CS00);
TCCR0B = (1 << CS01); 
return ;
}
