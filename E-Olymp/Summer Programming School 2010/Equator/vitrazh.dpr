program vitrazh;
{$APPTYPE CONSOLE}
var
  _a,_b,_c:byte;
  s:string;
  r,r1,a,b,c:real;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  read(r);
  r1:=r/2;
  read(s);
  _a:=ord(s[4])-48;
  _b:=ord(s[8])-48;
  _c:=ord(s[12])-48;

  c:=((pi-2)*r1*r1)/2;
  b:=pi*r1*r1-2*c;
  a:=c;

  writeln(a*_a:0:3,' ',b*_b:0:3,' ',c*_c:0:3);
  close(input);
  close(output);
end.
 