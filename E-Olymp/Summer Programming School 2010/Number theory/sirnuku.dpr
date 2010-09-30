program sirnuku;
{$APPTYPE CONSOLE}
var
  n,m:int64;
  i,t:longword;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  read(t);
  for i:=1 to t do
    begin
      read(n,m);
      if n mod (m+1)=0 then write(2) else write(1);
    end;
  writeln;
  close(input);
  close(output);
end.
