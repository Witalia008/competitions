program nutochka;
{$APPTYPE CONSOLE}
var
  mas:array[1..101]of record
                        x,y:real;
                      end;
  n,i:longword;
  r:real;
  ans:extended;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  read(n,r);
  for i:=1 to n do
    read(mas[i].x,mas[i].y);
  mas[n+1].x:=mas[1].x;
  mas[n+1].y:=mas[1].y;
  ans:=0;
  for i:=1 to n do
    ans:=ans+sqrt(sqr(mas[i].x-mas[i+1].x)+sqr(mas[i].y-mas[i+1].y));
  ans:=ans+2*pi*r;
  writeln(round(ans*100)/100:0:2);
  close(input);
  close(output);
end.
