#define BTN_PIN 12
#include "GyverButton.h"
#include "Wire.h" 
#include "LiquidCrystal_I2C.h"

float a = 0;
float b = 0;
float c = 0;
float sum = 0;
String mode = "+";

LiquidCrystal_I2C lcd(0x27,16,2);
GButton butt(BTN_PIN);

void setup() {
  lcd.init();                     
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("PhysicalOS");
  lcd.setCursor(4, 1);
  lcd.print("MaksPV");
  butt.setType(HIGH_PULL);
  delay(1000);
  lcd.clear();
}

void loop() {
  butt.tick();
  
  if (mode == "+") sum = a + b;
  if (mode == "-") sum = a - b;
  if (mode == "*") sum = a * b;
  if (mode == "/") sum = float(a) / float(b);
  if (mode == "ct") sum = pow(a, b);
  if (mode == "kk") sum = pow(a, double(1/b));
  if (mode == "sin") sum = sin(a);
  if (mode == "cos") sum = cos(a);
  if (mode == "log") sum = log(a);
  if (mode == "tan") sum = tan(a);
  
  lcd.setCursor(0, 0);
  lcd.print(String(a)+" "+mode+" "+String(b));
  lcd.setCursor(0,1);
  lcd.print("= "+String(sum, 8));
  
  if (butt.isSingle()) a = varManage("a", a);
  if (butt.isDouble()) b = varManage("b", b);
  if (butt.isTriple()) modManage();
  if (butt.isQuadruple()) sqEq();
  if (butt.isQuintuple()) trans();

}

float varManage(String x, float y){
  lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(x+": + - *1 /1 *-");
    while (true) {
      butt.tick();
      lcd.setCursor(0, 1);
      lcd.print(String(y, 10) + "       ");
      if (butt.isSingle()) y++;
      if (butt.isDouble()) y--;
      if (butt.isTriple()) y *= 10;
      if (butt.isQuadruple()) y /= 10;
      if (butt.isQuintuple()) y *= -1;
      if (butt.isHold()){
      lcd.clear();
      break;
      }
    }
  return y;
}

void modManage(){
  lcd.clear();
  lcd.print("nx + - * /");
  while (true){
    butt.tick();
    if (butt.isHold()) break;
    if (butt.isDouble()){mode = "+"; break;}
    if (butt.isTriple()){mode = "-"; break;}
    if (butt.isQuadruple()){mode = "*"; break;}
    if (butt.isQuintuple()){mode = "/"; break;}
    if (butt.isSingle()){
      lcd.clear();
      lcd.print("nx ct kk sin cos");
      while (true){
        butt.tick();
        if (butt.isHold()) break;
        if (butt.isDouble()){mode = "ct"; break;}
        if (butt.isTriple()){mode = "kk"; break;}
        if (butt.isQuadruple()){mode = "sin"; break;}
        if (butt.isQuintuple()){mode = "cos"; break;}
        if (butt.isSingle()){
          lcd.clear();
          lcd.print("log tan");
          while (true){
            butt.tick();
            if (butt.isHold()) break;
            if (butt.isSingle()){mode = "log"; break;}
            if (butt.isDouble()){mode = "tan"; break;}
          }break;
        }
      }break;
    }
  }
  lcd.clear();
}

void sqEq(){
  lcd.clear();
  while (true){
    butt.tick();
    lcd.setCursor(0,0);
    lcd.print(String(a, 1));
    lcd.setCursor(6,0);
    lcd.print(String(b, 1));
    lcd.setCursor(12,0);
    lcd.print(String(c, 1));
    if (a == 0){
      lcd.setCursor(0,1);
      lcd.print(String(-(c/b), 8));
    } else{
      lcd.setCursor(0,1);
      lcd.print(String((-b+sqrt(sq(b)-4*a*c))/(2*a), 4));
      lcd.setCursor(8,1);
      lcd.print(String((-b-sqrt(sq(b)-4*a*c))/(2*a), 4));
    }
    
    if (butt.isSingle()) a = varManage("a", a);
    if (butt.isDouble()) b = varManage("b", b);
    if (butt.isTriple()) c = varManage("c", c);
    if (butt.isQuadruple()){lcd.clear(); break;}
    if (butt.isQuintuple()) trans();
  }
}

void trans(){
  String choseVar = "a";
  lcd.clear();
  while (true) {
    butt.tick();
    lcd.setCursor(0,0);
    lcd.print("var: "+choseVar+"       ");
    if (butt.isHold()) break;
    if (butt.isSingle()){
      if (choseVar == "a") {choseVar = "b";}
      else if (choseVar == "b") {choseVar = "c";}
      else if (choseVar == "c") {choseVar = "a";}}
    if (butt.isDouble()){
      if (choseVar == "a") a = transManage();
      if (choseVar == "b") b = transManage();
      if (choseVar == "c") c = transManage();
      break;
    }
  }lcd.clear();
}

float transManage() {
  lcd.clear();
  lcd.print("nx sum a b c");
  while (true){
    butt.tick();
    if (butt.isHold()) {break;}
    if (butt.isDouble()){return sum; break;}
    if (butt.isTriple()){return a; break;}
    if (butt.isQuadruple()){return b; break;}
    if (butt.isQuintuple()){return c; break;}
    if (butt.isSingle()){
      lcd.clear();
      lcd.print("pi e G 0");
      while (true){
        butt.tick();
        if (butt.isHold()) break;
        if (butt.isSingle()){return 3.14159265358; break;}
        if (butt.isDouble()){return 2.71828182846; break;}
        if (butt.isTriple()){return 0.00000000006674; break;}
        if (butt.isQuadruple()){return 0; break;}
        }
      }
    }
  }
