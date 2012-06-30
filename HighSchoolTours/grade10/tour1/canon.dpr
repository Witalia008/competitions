program canon;
{$APPTYPE CONSOLE}
type
  long=record
    len:longword;
    nom:array[1..205]of byte;
  end;

function divmod(a:long;b:longword):long;
var
  ost,i:longword;
begin
  ost:=0;
  fillchar(result,sizeof(result),0);
  for i := 1 to a.len do
    begin
      ost:=ost*10+a.nom[i];
      result.nom[i]:=ost div b;
      ost:=ost mod b;
    end;
  result.len:=a.len;
end;

function ost(a:long;b:longword):longword;
var
  i,o:longword;
begin
  o:=0;
  for i := 1 to a.len do
    o:=(o*10+a.nom[i])mod b;
  ost:=o;  
end;

function comp_0(a:long):boolean;
var
  i:longword;
begin
  comp_0:=true;
  for i := 1 to a.len-1 do
    if a.nom[i]<>0 then comp_0:=false;
end;

var
  pr:array[1..500000]of boolean;
  n,i,j:longword;
  q:char;
  a:long;
  step,num:array[1..200000]of longword;
begin
  assign(input,'canon.dat');
  reset(input);
  assign(output,'canon.res');
  rewrite(output);
  i:=2;
  fillchar(pr,sizeof(pr),1);
  pr[1]:=false;
  while I<708 do
  begin
    if pr[i] then
      begin
        j:=2;
        while j*i<=500000 do
          begin
            pr[j*i]:=false;
            inc(j);
          end;
      end;
    inc(i);
  end;
  fillchar(a,sizeof(a),0);
  a.len:=0;
  while not eoln(input) do
    begin
      read(q);
      inc(a.len);
      a.nom[a.len]:=ord(q)-ord('0');
    end;
  i:=2;
  n:=0;
  while (not comp_0(a))or(a.nom[a.len]<>1) do
    begin
      j:=0;
      while ost(a,i)=0 do
        begin
          inc(j);
          a:=divmod(a,i);
        end;
      if j<>0 then
        begin
          inc(n);
          step[n]:=j;
          num[n]:=i;
        end;
      inc(i);
      while not pr[i] do inc(i);
    end;
  for i := 1 to n do
    begin
      j:=num[i];
      while j<>0 do
        begin
          j:=j div 10;
          write(' ');
        end;
      if step[i]<>1 then write(step[i]);
      if i<>n then write(' ');
    end;
  writeln;
  for i := 1 to n do
    begin
      write(num[i]);
      if step[i]<>1 then
        begin
          j:=step[i];
          while j<>0 do
            begin
              j:=j div 10;
              write(' ');
            end;
        end;
      if i<>n then write('*');
    end;
  writeln;
  close(input);
  close(output); 
end.
