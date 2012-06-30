program lucky;
{$APPTYPE CONSOLE}
const
  nmax=105;
type
  tmas=record
         num:array[1..nmax]of longint;
         len:longword;
       end;

function longlen(a:tmas):longword;
var
  i:longword;
begin
  i:=1;
  while (i<nmax)and(a.num[i]=0) do inc(i);
  longlen:=nmax-i+1;
end;

function sum(a,b:tmas):tmas;
var
  i,p,s:longword;
begin
  p:=0;
  fillchar(result,sizeof(result),0);
  for i:=nmax downto 1 do
    begin
      s:=a.num[i]+b.num[i]+p;
      p:=s div 10000;
      result.num[i]:=s mod 10000;
    end;
  result.len:=longlen(result);
end;

function sq(a:tmas):tmas;
var
  i,j,p,s:longword;
begin
  p:=0;
  fillchar(result,sizeof(result),0);
  for i:=nmax downto nmax-a.len-1 do
    if a.num[i]<>0 then
      for j:=nmax downto nmax-a.len-1 do
        begin
          s:=a.num[i]*a.num[j]+p+result.num[i+j-nmax];
          result.num[i+j-nmax]:=s mod 10000;
          p:=s div 10000;
        end;
  result.len:=longlen(result);
end;

{function minus(a,b:tmas):tmas;
var
  p,i:longword;
begin
  p:=0;
  fillchar(result,sizeof(result),0);
  for i:=nmax downto 1 do
    begin
      result.num[i]:=a.num[i]-b.num[i]-p;
      if result.num[i]<0 then
        begin
          inc(result.num[i],10);
          p:=1;
        end else p:=0;
    end;
  result.len:=longlen(result);
end;}
var
  n,s,i,j,k:longint;
  f{,su}:array[1..50,0..1000]of tmas;
  ans:tmas;
  ss:string;
begin
  Assign(Input,'lucky.dat');
  Reset(Input);
  Assign(Output,'lucky.res');
  Rewrite(Output);
  read(n,s);
  fillchar(f,sizeof(f),0);
  //fillchar(su,sizeof(su),0);
  for i:=0 to 9 do
    begin
      f[1][i].num[nmax]:=1;
      f[1][i].len:=1;
      //su[1][i]:=sum(su[1][i-1],f[1][i]);
    end;
  for i:=2 to n do
    for j:=0 to s+1 do
      begin
        if j<=s then
          begin
            k:=j;
            while (k>=0)and(j-k<10) do
              begin
                f[i][j]:=sum(f[i][j],f[i-1][k]);
                dec(k);
              end;
            {if (j-k>=0) then k:=j-k else k:=0;
            f[i][j]:=minus(su[i-1][j+1],su[i-1][k]); }
          end;
        //if j<>0 then su[i][j]:=sum(su[i-1][j],f[i][j]);
      end;
  ans:=sq(f[n][s]);
  write(ans.num[nmax-ans.len+1]);
  for i:=nmax-ans.len+2 to nmax do
    begin
      str(ans.num[i],ss);
      while length(ss)<4 do
        ss:=ss+'0';
      write(ss);
    end;
  {writeln;
  for i:=1 to n do
    begin
      for j:=0 to s do
        begin
          for k:=1 to nmax do
            write(f[i][j].num[k]);
          write(' ');
        end;
      writeln;
    end;
  writeln;
  for i:=1 to n do
    begin
      for j:=0 to s+1 do
        begin
          for k:=1 to nmax do
            write(su[i][j].num[k]);
          write(' ');
        end;
      writeln;
    end;   }
  Close(Input);
  Close(Output);
end.
