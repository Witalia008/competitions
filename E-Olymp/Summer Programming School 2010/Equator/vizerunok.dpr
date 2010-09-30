program vizerunok;
{$APPTYPE CONSOLE}
var
  l:longword;
  s:real;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  read(l);
  s:=pi*(l/2)*(l/2)*1.5;
  writeln(s:0:3);
  close(input);
  close(output);
end.
