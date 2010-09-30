program pustelia;
{$APPTYPE CONSOLE}
var
  i,d,b,ans:real;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  read(d,b);
  if b>=d then writeln(d:0:6)else
    begin
      i:=0;
      ans:=0;
      while ans<d do
        begin
          i:=i+1;
          ans:=ans+b/(2*i-1);
        end;
      ans:=ans-b/(2*i-1);
      i:=i+(d-ans)*(2*i-1)/b;
      i:=i-1;
      writeln(i*b:0:6);
    end;
  close(input);
  close(output);
end.
