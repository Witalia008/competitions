program piggy;
{$APPTYPE CONSOLE}
var
  f,e,a,n,i,j,m,min,max:longint;
  sum:array[0..100000]of longint;
  p,w:array[1..500]of longint;
begin
  Assign(Input,'piggy.in');
  reset(input);
  assign(output,'piggy.out');
  rewrite(output);
  read(e,f,n);
  a:=f-e;
  for i:=1 to n do
    read(p[i],w[i]);
  sum[0]:=0;
  for i:=1 to a do
    begin
      m:=-1;
      for j:=1 to n do
        if i-w[j]>=0 then
          if sum[i-w[j]]>=0 then
            if (m=-1)or(sum[i-w[j]]+p[j]<m) then
              m:=sum[i-w[j]]+p[j];
      sum[i]:=m;
    end;
  min:=sum[a];
  sum[0]:=0;
  for i:=1 to a do
    begin
      m:=-1;
      for j:=1 to n do
        if i-w[j]>=0 then
          if sum[i-w[j]]>=0 then
            if sum[i-w[j]]+p[j]>m then
              m:=sum[i-w[j]]+p[j];
      sum[i]:=m;
    end;
  max:=sum[a];
  if (min=-1)or(max=-1) then
      writeln('This is impossible.') 
   else
      writeln(min,' ',max);
  close(input);
  close(output);
end.
