program prfgdf;
{$APPTYPE CONSOLE}
var
  i,p,s:longword;
  j,l:integer;
  a,b,c:string;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  readln(a);
  readln(b);
  c:=a;
  p:=0;
  for i:=length(a) downto 1 do
    if ord(a[i])>=ord('a') then
      begin
        s:=(50-ord(a[i])+2*ord('a')-ord(b[i])+p)mod 26;
        p:=(50-ord(a[i])+2*ord('a')-ord(b[i])+p)div 26;
        c[i]:=chr(25-s+ord('a'));
      end else
      begin
        s:=(18-ord(a[i])+2*ord('0')-ord(b[i])+p)mod 10;
        p:=(18-ord(a[i])+2*ord('0')-ord(b[i])+p)div 10;
        c[i]:=chr(9-s+ord('0'));
      end;
  writeln(c);
  close(input);
  close(output);
end. 
