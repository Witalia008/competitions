program ivanov;
{$APPTYPE CONSOLE}
const
  nmax=10000;
type
  tmas=array[1..nmax]of byte;
{/////////////////////////////////////////////////////////////////////////////}
procedure longsum(q,w:tmas;var res:tmas);
var
  s,p,i:longword;
begin
  p:=0;
  for i := nmax downto 1 do
    begin
      s:=q[i]+w[i]+p;
      p:=s div 10;
      res[i]:=s mod 10;
    end;    
end;
{/////////////////////////////////////////////////////////////////////////////}
procedure longmn(q:tmas;o:longword;var res:tmas);
var
  p,s,i:longword;
begin
  p:=0;
  for i := nmax downto 1 do
    begin
      s:=q[i]*o+p;
      p:=s div 10;
      res[i]:=s mod 10;
    end;
end;
{/////////////////////////////////////////////////////////////////////////////}
var
  n,i,o:longword;
  a:array[1..3]of tmas;
  ans:tmas;
begin
  Assign(Input,'ivanov.in');
  Reset(Input);
  Assign(Output,'ivanov.out');
  Rewrite(Output);
  read(n);
  a[1][nmax]:=1;
  a[2][nmax]:=2;
  if n>3 then
  begin
  for i := 4 to n do
    begin
      longsum(a[1],a[2],ans);
      longmn(ans,i-1,a[3]);
      a[1]:=a[2];
      a[2]:=a[3];
      fillchar(a[3],sizeof(a[3]),0);
    end;
  o:=1;
  while a[2][o+1]=0 do
    inc(o);
  for i := o+1 to nmax do
    write(a[2][i]);
  writeln;
  end else
  begin
    if n=1 then writeln('0');
    if n=2 then writeln('1');
    if n=3 then writeln('2');
  end;
  Close(Output);
  Close(Input);
end.
