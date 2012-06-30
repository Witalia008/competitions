program poland_zapis;
{$APPTYPE CONSOLE}
uses
  math;
type
  tmas=record
    len:longword;
    op:array[1..1000]of string;
  end;
  tt=record
    len:longword;
    n:array[1..1000]of extended;
  end;
function prio(a,b:string):byte;
begin
  if (a='sin')or(a='cos')or(a='tg')or(a='ctg')or(a='ln')or(a='^') then prio:=1;
  if (a='*')or(a='/') then
    begin
      if (b='+')or(b='-')or(b='*')or(b='/') then prio:=1 else prio:=0;
    end;
  if (a='+')or(a='-') then
    begin
      if (b='+')or(b='-') then prio:=1 else prio:=0;
    end;
end;

function stf(s:string):extended;
var
  ans,k:extended;
begin
  if pos('.',s)=0 then
    begin
      ans:=0;
      while length(s)<>0 do
        begin
          ans:=ans*10+ord(s[1])-48;
          delete(s,1,1);
        end;
    end else
    begin
      ans:=0;
      while s[1]<>'.' do
        begin
          ans:=ans*10+ord(s[1])-48;
          delete(s,1,1);
        end;
      delete(s,1,1);
      k:=0;
      while length(s)<>0 do
        begin
          k:=k+ord(s[1])-48;
          k:=k/10;
          delete(s,1,1);
        end;
      ans:=ans+k;
    end;
  stf:=ans;
end;

var
  s,c:string;
  st,res:tmas;
  a,b:extended;
  ans:tt;
  i:longword;
begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  read(s);
  s:='('+s+')';
  fillchar(st,sizeof(st),0);
  fillchar(res,sizeof(res),0);
  fillchar(ans,sizeof(ans),0);
  while s<>'' do
    begin
      if s[1] in ['0'..'9'] then
        begin
          c:='';
          while s[1] in ['0'..'9','.'] do
            begin
              c:=c+s[1];
              delete(s,1,1);
            end;
          inc(res.len);
          res.op[res.len]:=c;
        end else
      if s[1] in ['-','+','*','/','^'] then
        begin
          while (st.len>0)and(prio(st.op[st.len],s[1])=1) do
            begin
              inc(res.len);
              res.op[res.len]:=st.op[st.len];
              dec(st.len);
            end;
          inc(st.len);
          st.op[st.len]:=s[1];
          delete(s,1,1);
        end else
      if (copy(s,1,3)='cos')or(copy(s,1,3)='sin')or(copy(s,1,3)='ctg') then
        begin
          while (st.len>0)and(prio(st.op[st.len],copy(s,1,3))=1) do
            begin
              inc(res.len);
              res.op[res.len]:=st.op[st.len];
              st.op[st.len]:='';
              dec(st.len);
            end;
          inc(st.len);
          st.op[st.len]:=copy(s,1,3);
          delete(s,1,3);
        end else
      if (copy(s,1,2)='tg')or(copy(s,1,2)='ln') then
        begin
          while (st.len>0)and(prio(st.op[st.len],copy(s,1,2))=1) do
            begin
              inc(res.len);
              res.op[res.len]:=st.op[st.len];
              st.op[st.len]:='';
              dec(st.len);
            end;
          inc(st.len);
          st.op[st.len]:=copy(s,1,2);
          delete(s,1,2);
        end else
      if (copy(s,1,4)='sqrt') then
        begin
          while (st.len>0)and(prio(st.op[st.len],copy(s,1,4))=1) do
            begin
              inc(res.len);
              res.op[res.len]:=st.op[st.len];
              st.op[st.len]:='';
              dec(st.len);
            end;
          inc(st.len);
          st.op[st.len]:=copy(s,1,4);
          delete(s,1,4);
        end else
      if s[1]='(' then
        begin
          inc(st.len);
          st.op[st.len]:='(';
          delete(s,1,1);
        end else
      if s[1]=')' then
        begin
          i:=st.len;
          while (st.op[st.len]<>'(')and(st.len<>0) do
            begin
              inc(res.len);
              res.op[res.len]:=st.op[st.len];
              st.op[st.len]:='';
              dec(st.len);
            end;
          st.op[st.len]:='';
          dec(st.len);
          delete(s,1,1);
        end;
    end;
  {while st.len<>0 do
    begin
      inc(res.len);
      res.op[res.len]:=st.op[st.len];
      dec(st.len);
    end;  }
  for i := 1 to res.len do
    if res.op[i][1] in ['0'..'9'] then
      begin
        inc(ans.len);
        ans.n[ans.len]:=stf(res.op[i]);
      end else
    if res.op[i]='-' then
      begin
        a:=ans.n[ans.len];
        b:=ans.n[ans.len-1];
        ans.n[ans.len]:=0;
        dec(ans.len);
        ans.n[ans.len]:=b-a;
      end else
    if res.op[i]='+' then
      begin
        a:=ans.n[ans.len];
        b:=ans.n[ans.len-1];
        ans.n[ans.len]:=0;
        dec(ans.len);
        ans.n[ans.len]:=a+b;
      end else
    if res.op[i]='*' then
      begin
        a:=ans.n[ans.len];
        b:=ans.n[ans.len-1];
        ans.n[ans.len]:=0;
        dec(ans.len);
        ans.n[ans.len]:=a*b;
      end else
    if res.op[i]='/' then
      begin
        a:=ans.n[ans.len];
        b:=ans.n[ans.len-1];
        ans.n[ans.len]:=0;
        dec(ans.len);
        if b<>0 then ans.n[ans.len]:=b/a else
          begin
            writeln('Error');
            halt;
          end;
      end else
    if res.op[i]='sin' then
      begin
        ans.n[ans.len]:=sin(ans.n[ans.len]*pi/180);
      end else
    if res.op[i]='cos' then
      begin
        ans.n[ans.len]:=cos(ans.n[ans.len]*pi/180);
      end else
    if res.op[i]='tg' then
      begin
        ans.n[ans.len]:=sin(ans.n[ans.len]*pi/180)/cos(ans.n[ans.len]*pi/180);
      end else
    if res.op[i]='ctg' then
      begin
        ans.n[ans.len]:=cos(ans.n[ans.len]*pi/180)/sin(ans.n[ans.len]*pi/180);
      end else
    if res.op[i]='ln' then
      begin
        ans.n[ans.len]:=ln(ans.n[ans.len]);
      end else
    if res.op[i]='sqrt' then
      begin
        a:=ans.n[ans.len];
        b:=ans.n[ans.len-1];
        ans.n[ans.len]:=0;
        dec(ans.len);
        ans.n[ans.len]:=power(a,1/b);
      end else
    if res.op[i]='^' then
      begin
        a:=ans.n[ans.len];
        b:=ans.n[ans.len-1];
        ans.n[ans.len]:=0;
        dec(ans.len);
        ans.n[ans.len]:=power(b,a);
      end;
  writeln(ans.n[1]:0:5);
  close(input);
  close(output);
end.
