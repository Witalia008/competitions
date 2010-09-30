program pobudova_kola;
{$APPTYPE CONSOLE}
var
  x1,x2,x3,y1,y2,y3,a,b,c,p,r,s:extended;
  F1,f2:textfile;
begin
  assign(f1,'input.txt');
  reset(f1);
  assign(f2,'output.txt');
  rewrite(f2);
  while not eof(f1) do
    begin
      readln(f1,x1,y1,x2,y2,x3,y3);
      a:=sqrt(sqr(x1-x2)+sqr(y1-y2));
      b:=sqrt(sqr(x3-x2)+sqr(y3-y2));
      c:=sqrt(sqr(x1-x3)+sqr(y1-y3));
      p:=(a+b+c)/2;
      s:=sqrt(p*(p-a)*(p-b)*(p-c));
      r:=(a*b*c)/(4*s);
      writeln(f2,2*pi*r:0:2);
    end;
  close(f1);
  close(f2);
end.
