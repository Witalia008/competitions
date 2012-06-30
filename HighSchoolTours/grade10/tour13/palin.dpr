program palin;
{$APPTYPE CONSOLE}
var
  s:string;
  i,j:longword;
begin
  assign(input,'palin.in');
  reset(input);
  assign(output,'palin.out');
  rewrite(output);
  read(s);
  i:=1;
  j:=length(s)+1;
  s:=s+s[1];
  inc(i);dec(j);
  while (i<j) do
    begin
      if (s[i]=s[j]) then
        begin
          inc(i);
          dec(j);
        end else
        begin
          insert(s[i],s,j+1);
          inc(i);
        end;
    end;
  writeln(s);
  close(input);
  close(output);
end.
