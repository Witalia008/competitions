program poligonu;
{$APPTYPE CONSOLE}
var
  x1,y1:extended;
  n,i,j:longword;
  mas:array[1..200000]of record
                           x,y:extended;
                         end;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  while not eof(input) do
    begin
      read(n);
      j:=0;
      x1:=0;
      y1:=0;
      for i:=1 to n do
        begin
          inc(j);
          read(mas[i].x,mas[i].y);
          x1:=x1+mas[i].x;
          y1:=y1+mas[i].y;
          if j mod 2=0 then
            begin
              x1:=x1-2*mas[i].x;
              y1:=y1-2*mas[i].y;
            end;
        end;
      readln;
      write(n);
      write(' ',x1:0:6,' ',y1:0:6);
      for i:=1 to n-1 do
        begin
          x1:=2*mas[i].x-x1;
          y1:=2*mas[i].y-y1;
          write(' ',x1:0:6,' ',y1:0:6);
        end;
      writeln;  
    end;
  close(input);
  close(output);
end.
