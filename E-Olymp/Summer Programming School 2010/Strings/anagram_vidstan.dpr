program anagram_vidstan;
{$APPTYPE CONSOLE}

procedure swap(var a,b:char);
var
  t:char;
begin
  t:=a;
  a:=b;
  b:=t;
end;

procedure sort(var a:string;l,r:longword);
var
  et,i,j:longword;
begin
  if (l=r-1)and(ord(a[l])<ord(a[r]))then exit;
  et:=ord(a[(l+r)div 2]);
  i:=l;
  j:=r;
  while i<j do
    begin
      while ord(a[i])<et do inc(i);
      while ord(a[j])>et do dec(j);
      if i<j then
        begin
          swap(a[i],a[j]);
          inc(i);
          dec(j);
        end;
    end;
  if i<r then sort(a,i,r);
  if j>l then sort(a,l,j);
end;

var
  a,b:string;
  n,i,j,l,ans:longword;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  readln(n);
  for l:=1 to n do
    begin
      readln(a);
      readln(b);
      if length(a)<>0 then sort(a,1,length(a));
      if length(b)<>0 then sort(b,1,length(b));
      a:=a+'~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~';
      b:=b+'~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~';
      ans:=0;
      i:=1;
      while a<>b do
        begin
          while a[i]=b[i] do inc(i);
          if ord(a[i])<ord(b[i]) then delete(a,i,1) else
            delete(b,i,1);
          inc(ans);
        end;
      writeln('Case #',l,':  ',ans);
    end;
  close(input);
  close(output);
end.
