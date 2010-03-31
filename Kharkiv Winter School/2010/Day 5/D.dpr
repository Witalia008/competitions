program stari_pisni_pro_golovne_3;
 {$APPTYPE CONSOLE}
 var
  n,i,j,m,d,k,max:longword;
  t:array[0..100,0..300,0..300]of longword;
  l:array[1..300]of longword;
 begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  read(m,d,n);
  for i:=1 to n do
    read(l[i]);
  fillchar(t,sizeof(t),0);
  t[0][0][0]:=0;
  for i:=0 to m do
    for j:=0 to n do
      for k:=0 to d do
        if k<>0 then
          begin
            max:=0;
            if (j>0)and(t[i][j-1][k]>max) then max:=t[i][j-1][k];
            if (1+t[i][j-1][k-l[j]]>max)and(j>0)and(k>=l[j]) then max:=1+t[i][j-1][k-l[j]];
            if (k>0)and(t[i][j][k-1]>max) then max:=t[i][j][k-1];
            t[i][j][k]:=max;
          end else
          if (i>0) then t[i][j][0]:=t[i-1][j][d];
  writeln(t[m-1][n][d]);
  close(input);
  close(output);
 end.
