program geometruchniy_paradoks;
{$APPTYPE CONSOLE}
var
  s:string;
  n,r1,r2,i,j,t:longint;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  readln(n);
  for j:=1 to n do
    begin
      readln(s);
      i:=1;
      s:=s+' ';
      while i<=length(s) do
        begin
          if s[i]=' ' then
            while s[i+1]=' ' do delete(s,i,1);
          inc(i);
        end;
      while s[length(s)]=' ' do
        delete(s,length(s),1);
      if pos(' ',s)=0 then
        begin
          val(s,t,i);
          writeln(pi*t*t/8:0:4);
        end else
        begin
          r1:=0;
          r2:=0;
          for i:=pos(' ',s)+1 to length(s) do
            r2:=r2*10+ord(s[i])-48;
          for i:=1 to pos(' ',s)-1 do
            r1:=r1*10+ord(s[i])-48;
          writeln(pi*sqr(r1+r2)-pi*r1*r1-pi*r2*r2:0:4);
        end;
    end;
  close(input);
  close(output);
end.
 