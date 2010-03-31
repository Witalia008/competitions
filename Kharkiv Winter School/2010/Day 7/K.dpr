program potuzhnist;
{$apptype console}
const
  en=2222;
  digit:set of char=['0'..'9'];
  big:set of char=['A'..'Z'];

function bits(k:integer):integer;
var
  ans:integer;
begin
  ans:=0;
  while(k>0) do
    begin
      ans:=ans+(k mod 2);
      k:=k div 2;
    end;
  bits:=ans;
end;

var
  s:string;
  k:array[0..2*en]of integer;
  a:array[0..en]of integer;
  count:array[0..8*en+1]of integer;
  n,i,ans,sum,j:longword;

begin
  assign(input,'input.txt');
  assign(output,'output.txt');
  reset(input);
  rewrite(output);
  read(s);
  n:=length(s) div 2;
  fillchar(count,sizeof(count),0);
  for i:=1 to 2*n do
    if(s[i]in digit) then
      k[i]:=ord(s[i])-48 else
        if s[i] in big then
          k[i]:=ord(s[i])-ord('A')+10 else
            k[i]:=ord(s[i])-ord('a')+10;
  for i:=1 to n do
    a[i]:=bits(k[2*i])+bits(k[2*i-1]);
  for i:=1 to n do
    begin
      sum:=0;
      for j:=i to n do
        begin
          sum:=sum+a[j];
          if (sum=4*(j-i+1)) then
            inc(count[sum]);
        end;
    end;
  ans:=4;
  for i:=2 to 2*n do
    if(count[4*i]>=count[ans])then
      ans:=4*i;
  writeln(ans);
  close(input);
  close(output);
end.
