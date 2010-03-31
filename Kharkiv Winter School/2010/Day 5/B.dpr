program zakupivlia_biletiv;
 {$APPTYPE CONSOLE}
///////////////////////////////////////////////////////
function min(a,b,c:longword):longword;
 var
  i:longword;
 begin
  if a<b then i:=a else i:=b;
  if i<c then min:=i else min:=c;
 end;
////////////////////////////////////////////////////////
var
  a,b,c,f:array[0..5100]of longword;
  n,i,j:longword;
 begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  read(n);
  for i:=1 to n do
    read(a[i],b[i],c[i]);
  f[0]:=0;
  f[1]:=a[1];
  f[2]:=min(a[1]+a[2],b[1],maxint);
  for i:=3 to n do
    f[i]:=min(f[i-1]+a[i],f[i-2]+b[i-1],f[i-3]+c[i-2]);
  writeln(f[n]);
  close(input);
  close(output);
 end.
