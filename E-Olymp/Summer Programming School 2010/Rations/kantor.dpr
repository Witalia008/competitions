program kantor;
{$APPTYPE CONSOLE}
var
 n,m,i,j:int64;
begin
 assign(input,'input.txt');
 reset(input);
 assign(output,'output.txt');
 rewrite(output);
 while not eof(input) do
 begin
 read(n);
 i:=0;
 j:=1;
 m:=0;
 while m<n do
   begin
     inc(i);
     m:=m+i;
   end;
 m:=m-i+1;
 i:=i-n+m;
 j:=j+n-m;
 if (i<>0) and (j<>0) then writeln(i,'/',j);
 end;
 close(input);
 close(output);
end.
