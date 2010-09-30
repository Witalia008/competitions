program hourse;
{$APPTYPE CONSOLE}
const
  nmax=50;
  k:array[1..8,1..2]of smallint=((1,2),(1,-2),(-1,2),(-1,-2),(2,1),(2,-1),(-2,1),(-2,-1));
var
  a,p:array[-1..nmax+2,-1..nmax+2] of smallint;
  queue:array[1..2,1..nmax*nmax]of byte;
  i,j,n,head,tail,iss,jss,iff,jff,l:longword;
  q:char;
  fl:boolean;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  readln(n);
  fillchar(a,sizeof(a),-1);
  fl:=true;
  for i:=1 to n do
    begin
      for j:=1 to n do
        begin
          read(q);
          if (q='@')and(fl) then
            begin
              a[i,j]:=0;
              iss:=i;
              jss:=j;
              fl:=false;
            end else
          if (q='@') then
            begin
              a[i,j]:=0;
              iff:=i;
              jff:=j;
            end;
          if q='.' then a[i,j]:=0;
        end;
      readln;
    end;
  fillchar(p,sizeof(p),0);
  fillchar(queue,sizeof(queue),0);
  head:=1;
  tail:=2;
  queue[1,1]:=iss;
  queue[2,1]:=jss;
  p[iss,jss]:=1;
  while head<tail do
    begin
      i:=queue[1,head];
      j:=queue[2,head];
      inc(head);
      for l:=1 to 8 do
        if ((p[i+k[l,1],j+k[l,2]]=0)or(p[i+k[l,1],j+k[l,2]]>p[i,j]+1))and(a[i+k[l,1],j+k[l,2]]=0) then
          begin
            p[i+k[l,1],j+k[l,2]]:=p[i,j]+1;
            queue[1,tail]:=i+k[l,1];
            queue[2,tail]:=j+k[l,2];
            inc(tail);
          end;
    end;
  if p[iff,jff]=0 then writeln('Impossible')else
    begin
      a[iff,jff]:=2;
      i:=iff;
      j:=jff;
      while (i<>iss)or(j<>jss) do
        begin
          l:=1;
          while p[i+k[l,1],j+k[l,2]]<>p[i,j]-1 do inc(l);
          i:=i+k[l,1];
          j:=j+k[l,2];
          a[i,j]:=2;
        end;
      a[iss,jss]:=2;
      for i:=1 to n do
        begin
          for j:=1 to n do
            if a[i,j]=-1 then write('#') else
             if a[i,j]=0 then write('.') else
                if a[i,j]=2 then write('@');
          writeln;
        end;
    end;
  close(input);
  close(output);
end.

