program diplomat_stosunki;
{$APPTYPE CONSOLE}
var
  x1,x2,y2,y1,xs,ys:int64;
  n,i:longword;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  while not eof(input) do
    begin
      read(n);
      if n<>0 then
        begin
          write(n);
          read(xs,ys);
          x1:=xs;
          y1:=ys;
          for i:=2 to n do
            begin
              read(x2,y2);
              write(' ',(x1+x2)/2:0:6,' ',(y1+y2)/2:0:6);
              x1:=x2;
              y1:=y2;
            end;
          readln;
          writeln(' ',(xs+x2)/2:0:6,' ',(ys+y2)/2:0:6);
        end;
    end;
  close(input);
  close(output);
end.
