program cili;
{$APPTYPE CONSOLE}
/////////////////////////////////////////////////////
function max(a,b:int64):int64;
begin
  if b>a then max:=b else max:=a;
end;
/////////////////////////////////////////////////////////
function min(a,b:int64):int64;
begin
  if a<b then min:=a else min:=b;
end;
///////////////////////////////////////////////////////
function GCD(a,b:longword):longword;
begin
  while (a<>0)and(b<>0) do
    if a>b then a:=a mod b else b:=b mod a;
  if b=0  then GCD:=a else GCD:=b;
end;
///////////////////////////////////////////////////////
function ks(x1,y1,x2,y2:int64):int64;
var
  len1,len2,ans:int64;
begin
  len1:=abs(x2-x1);
  len2:=abs(y2-y1);
  if min(len1,len2)<>0 then
    begin
      if max(len1,len2) mod (min(len1,len2))=0 then
        ans:=min(len1,len2)+1 else ans:=GCD(len1,len2)+1;
    end else
    ans:=max(len1,len2)+1;
  ks:=ans;
end;
/////////////////////////////////////////////////
var
 mas:array[1..1000]of record
                        x,y:int64;
                      end;
 s:double;
 i,n:longword;
 b:int64;
begin
  Assign(Input,'input.txt');
  Reset(Input);
  Assign(Output,'output.txt');
  Rewrite(Output);
  read(n);
  for i := 1 to n do
    read(mas[i].x,mas[i].y);
  s:=0;
  for i := 1 to n- 1 do
    s:=s+(mas[i+1].x*mas[i].y-mas[i].x*mas[i+1].y)/2;
  s:=s+(mas[1].x*mas[n].y-mas[n].x*mas[1].y)/2;
  b:=ks(mas[1].x,mas[1].y,mas[n].x,mas[n].y);
  for i:=1 to n-1 do
    b:=b+ks(mas[i].x,mas[i].y,mas[i+1].x,mas[i+1].y);
  dec(b,n);  
  writeln(round(s+1-b/2));  
  Close(Input);
  Close(Output);
end.
