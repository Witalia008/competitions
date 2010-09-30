program lanciugovi_drobu;
{$APPTYPE CONSOLE}
var
  sol:array[1..1000000]of longword;
  i,j,count,nom:longword;
begin
  Assign(Input,'input.txt');
  Reset(Input);
  Assign(Output,'output.txt');
  Rewrite(Output);
  while not eof(input) do
    begin
      read(i,j);
      if not eof(input) then
      begin
      count:=0;
      nom:=0;
      while (i<>0)and(j<>0) do
        begin
          inc(nom);
          if nom mod 2=1 then
            begin
              inc(count);
              sol[count]:=i div j;
              i:=i mod j;
            end else
            begin
              inc(count);
              sol[count]:=j div i;
              j:=j mod i;
            end;
        end;
      if count<>0 then
        begin
          if count>1 then
            if sol[count]=1 then
              begin
                dec(count);
                inc(sol[count]);
              end;
          write('[');
          write(sol[1]);
          if count>1 then
            begin
              write(';');
              if count>2 then
                for i := 2 to Count-1  do
                  write(sol[i],',');
              write(sol[count]);
            end;
          writeln(']');
        end;
      end;  
    end;
  Close(Input);
  Close(Output);
end.
