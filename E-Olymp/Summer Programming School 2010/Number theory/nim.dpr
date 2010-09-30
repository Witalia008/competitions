program nim;
{$APPTYPE CONSOLE}
var
  n,i,j,x,ans,l:longword;
  mas:array[1..1000]of longword;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  read(n);
  while n<>0 do
    begin
      read(x);
      mas[1]:=x;
      for i:=2 to n do
        begin
          read(mas[i]);
          x:=x xor mas[i];
        end;
      if x=0 then writeln(0) else
        begin
          j:=0;
          while x>0 do
            begin
              inc(j);
              x:=x div 2;
            end;
          ans:=0;
          for i:=1 to n do
            begin
              l:=0;
              x:=mas[i];
              while l<>j-1 do
                begin
                  inc(l);
                  x:=x div 2;
                end;
              if x mod 2=1 then inc(ans);  
            end;
          writeln(ans);
        end;
      read(n);
    end;
  close(input);
  close(output);
end.
 