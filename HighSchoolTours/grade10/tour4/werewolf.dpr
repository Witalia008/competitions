program werewolf;
{$APPTYPE CONSOLE}
const
  nmax=1000;

function max(a,b:longword):longword;
begin
  if a<b then max:=b else max:=a;
end;

var
  s,ans:string;
  i,j,n:longword;
  f:array[0..nmax,0..nmax]of longword;
begin
  Assign(Input,'werewolf.dat');
  Reset(Input);
  Assign(Output,'werewolf.res');
  Rewrite(Output);
  read(s);
  n:=length(s);
  fillchar(f,sizeof(f),0);
  if s[1] in ['A'..'Z'] then
    s[1]:=chr(ord(s[1])+ord('a')-ord('A'));
  for i := 1 to n do
    for j := 1 to n do
      if s[j]=s[n-i+1] then
        f[i][j]:=f[i-1][j-1]+1 else
          f[i][j]:=max(f[i][j-1],f[i-1][j]);
  ans:='';
  i:=n;
  j:=n;
  while length(ans)<>f[n][n] do
    begin
      if s[j]=s[n-i+1] then
        begin
          ans:=s[j]+ans;
          dec(i);
          dec(j);
        end else
      begin
        if f[i-1][j]>f[i][j-1] then dec(i) else dec(j);
      end;
    end;
  ans[1]:=chr(ord(ans[1])-ord('a')+ord('A'));
  writeln(ans);
  Close(Input);
  Close(Output);
end.
