program labirint;
{$APPTYPE CONSOLE}
const
  nmax=33;
  k:array[1..4,1..2]of smallint=((0,1),(0,-1),(1,0),(-1,0));
var
  a,p:array[0..nmax+1,0..nmax+1]of smallint;
  i,j,head,tail,l,ans,ks,n:longword;
  queue:array[1..2,1..nmax*nmax*2]of longword;
  q:char;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  readln(n);
  fillchar(a,sizeof(a),-1);
  fillchar(p,sizeof(p),0);
  for i:=1 to n do
    begin
      for j:=1 to n do
        begin
          read(q);
          if q='.' then a[i,j]:=0;
        end;
      readln;
    end;
  head:=1;
  tail:=2;
  fillchar(queue,sizeof(queue),0);
  queue[1,1]:=1;
  queue[2,1]:=1;
  p[1,1]:=1;
  while head<tail do
    begin
      i:=queue[1,head];
      j:=queue[2,head];
      inc(head);
      for l:=1 to 4 do
        if ((p[i+k[l,1],j+k[l,2]]>p[i,j]+1)or(p[i+k[l,1],j+k[l,2]]=0))and(a[i+k[l,1],j+k[l,2]]=0) then
          begin
            p[i+k[l,1],j+k[l,2]]:=p[i,j]+1;
            queue[1,tail]:=i+k[l,1];
            queue[2,tail]:=j+k[l,2];
            inc(tail);
          end;
    end;
  head:=1;
  tail:=2;
  fillchar(queue,sizeof(queue),0);
  queue[1,1]:=n;
  queue[2,1]:=n;
  p[n,n]:=1;
  while head<tail do
    begin
      i:=queue[1,head];
      j:=queue[2,head];
      inc(head);
      for l:=1 to 4 do
        if ((p[i+k[l,1],j+k[l,2]]>p[i,j]+1)or(p[i+k[l,1],j+k[l,2]]=0))and(a[i+k[l,1],j+k[l,2]]=0) then
          begin
            p[i+k[l,1],j+k[l,2]]:=p[i,j]+1;
            queue[1,tail]:=i+k[l,1];
            queue[2,tail]:=j+k[l,2];
            inc(tail);
          end;
    end;
  ans:=0;
  for i:=1 to n do
    for j:=1 to n do
      if (p[i,j]<>0)then
        begin
          ks:=0;
          if a[i-1,j]=-1 then ks:=ks+1;
          if a[i+1,j]=-1 then ks:=ks+1;
          if a[i,j-1]=-1 then ks:=ks+1;
          if a[i,j+1]=-1 then ks:=ks+1;
          ans:=ans+ks*9;
        end;
  writeln(ans-36);
  close(input);
  close(output);
end.
 