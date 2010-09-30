program sova;
{$APPTYPE CONSOLE}
var
  n:int64;
begin
  read(n);
  if frac(sqrt(n+1))=0 then writeln(n,' ',n)else
    writeln(sqr(trunc(sqrt(n)))-1,' ',sqr(trunc(sqrt(n))+1)-1);
end.
