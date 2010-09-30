program neskorotni_pravulni_drobu;
{$APPTYPE CONSOLE}

function phi(n:longword):longword;
var
  res:longword;
  i:longword;
begin
  res:=n;
  for i:=2 to round(sqrt(n)) do
    if n mod i=0 then
      begin
        while n mod i=0 do
          n:=n div i;
        res:=res-res div i;
      end;
    if n>1 then res:=res-res div n;
    phi:=res;
end;

var
 n:longword;
begin
 assign(input,'input.txt');
 reset(input);
 assign(output,'output.txt');
 rewrite(output);
 read(n);
 while n<>0 do
   begin
     writeln(phi(n));
     read(n);
   end;
 close(input);
 close(output);
end. 
