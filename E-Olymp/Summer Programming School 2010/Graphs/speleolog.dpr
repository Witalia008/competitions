program speleolog;
{$APPTYPE CONSOLE}
const
  nmax=30;
  kk:array[1..6,1..3]of smallint=((0,0,1),(0,0,-1),(0,1,0),(0,-1,0),(1,0,0),(-1,0,0));
var
  a,p:array[0..nmax+1,0..nmax+1,0..nmax+1]of smallint;
  i,j,l,iss,jss,lss,head,tail,n,k,min:longword;
  queue:array[1..3,1..nmax*nmax*nmax*2]of byte;
  q:char;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  readln(n);
  fillchar(a,sizeof(a),-1);
  for i:=1 to n do
    begin
      readln;
      for j:=1 to n do
        begin
          for l:=1 to n do
            begin
              read(q);
              if q='.' then
                a[i,j,l]:=0 else
                  if q='S' then
                    begin
                      a[i,j,l]:=0;
                      iss:=i;
                      jss:=j;
                      lss:=l;
                    end;
            end;
          readln;
        end;
    end;
  fillchar(p,sizeof(p),0);
  head:=1;
  tail:=2;
  queue[1,1]:=iss;
  queue[2,1]:=jss;
  queue[3,1]:=lss;
  p[iss,jss,lss]:=1;
  while head<tail do
    begin
      i:=queue[1,head];
      j:=queue[2,head];
      l:=queue[3,head];
      inc(head);
      for k:=1 to 6 do
        if ((p[i+kk[k,1],j+kk[k,2],l+kk[k,3]]=0)or(p[i+kk[k,1],j+kk[k,2],l+kk[k,3]]>p[i,j,l]+1))and(a[i+kk[k,1],j+kk[k,2],l+kk[k,3]]=0) then
          begin
            p[i+kk[k,1],j+kk[k,2],l+kk[k,3]]:=p[i,j,l]+1;
            queue[1,tail]:=i+kk[k,1];
            queue[2,tail]:=j+kk[k,2];
            queue[3,tail]:=l+kk[k,3];
            inc(tail);
          end;
    end;
  min:=maxint;
  for i:=1 to n do
    for j:=1 to n do
      if (a[1,i,j]=0)and(p[1,i,j]<min)and(p[1,i,j]<>0) then
        min:=p[1,i,j];
  writeln(min-1);
  close(input);
  close(output);
end.
