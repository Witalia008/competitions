program tort_vid_toli;
{$APPTYPE CONSOLE}
function gcd(a,b:longword):longword;
begin
  while (a<>0)and(b<>0) do
    if a>b then a:=a mod b else b:=b mod a;
  if a=0 then gcd:=b else gcd:=a;
end;

var
  n,m:longword;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  read(n,m);
  writeln(n+m-gcd(n,m));
  close(input);
  close(output);
end.
 