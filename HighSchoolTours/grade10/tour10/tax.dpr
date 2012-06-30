program tax;
{$APPTYPE CONSOLE}
const
  day=1440;
type
  tmas=record
    next,dest,pay,timel,timer:word;
  end;
var
  n,m,t,a,b,et,i,j,pn,pt,pp,ai,bi,ci,en:word;
  list:array[1..65000]of tmas;
  head,ppay,ttime:array[1..250]of longword;

procedure add(u,v,w,tl,tr:longword);
begin
  inc(en);
  list[en].dest:=v;
  list[en].next:=head[u];
  head[u]:=en;
  list[en].pay:=w;
  list[en].timel:=tl;
  list[en].timer:=tr;
end;

procedure bfstime(i,t:longword);
var
  j,k:longword;
begin
  j:=head[i];
  while j<>0 do
    begin
      if (t<=list[j].timel) then
        k:=list[j].timel-t else
          k:=day-t+list[j].timel;
      if (ttime[list[j].dest]>ttime[i]+k+list[j].timer-list[j].timel) then
        begin
          ttime[list[j].dest]:=ttime[i]+k+list[j].timer-list[j].timel;
          ppay[list[j].dest]:=ppay[i]+list[j].pay;
          bfstime(list[j].dest,(ttime[i]+k+list[j].timer-list[j].timel)mod day)
        end else
      if (ttime[list[j].dest]=ttime[i]+k+list[j].timer-list[j].timel)and(ppay[list[j].dest]>ppay[i]+list[j].pay) then
        begin
          ppay[list[j].dest]:=ppay[i]+list[j].pay;
          bfstime(list[j].dest,(ttime[i]+k+list[j].timer-list[j].timel)mod day)
        end;
      j:=list[j].next;
    end;
end;

procedure bfspay(i,t:longword);
var
  j,k:longword;
begin
  j:=head[i];
  while j<>0 do
    begin
      if (t<=list[j].timel) then
        k:=list[j].timel-t else
          k:=day-t+list[j].timel;
      if (ppay[list[j].dest]>ppay[i]+list[j].pay) then
        begin
          ttime[list[j].dest]:=ttime[i]+k+list[j].timer-list[j].timel;
          ppay[list[j].dest]:=ppay[i]+list[j].pay;
          bfspay(list[j].dest,(ttime[i]+k+list[j].timer-list[j].timel)mod day)
        end else
      if (ppay[list[j].dest]=ppay[i]+list[j].pay)and(ttime[list[j].dest]>ttime[i]+k+list[j].timer-list[j].timel) then
        begin
          ttime[list[j].dest]:=ttime[i]+k+list[j].timer-list[j].timel;
          bfspay(list[j].dest,(ttime[i]+k+list[j].timer-list[j].timel)mod day)
        end;
      j:=list[j].next;
    end;
end;

begin
  assign(input,'tax.in');
  reset(input);
  assign(output,'tax.out');
  rewrite(output);
  readln(n,m,t,a,b);
  en:=0;
  fillchar(head,sizeof(head),0);
  for i :=1 to m do
    begin
      read(pn,pt,pp);
      while not eoln(input) do
        begin
          read(ai,bi,ci);
          add(pn,ai,ci,pt,bi);
          pn:=ai;pt:=bi;pp:=ci;
        end;
      readln;
    end;
  for i := 1 to n do
    begin
      ppay[i]:=maxlongint div 2;
      ttime[i]:=maxlongint div 2;
    end;
  ppay[a]:=0;
  ttime[a]:=t;
  bfstime(a,t);
  write(ttime[b],' ',ppay[b],' ');
  for i := 1 to n do
    begin
      ppay[i]:=maxlongint div 2;
      ttime[i]:=maxlongint div 2;
    end;
  ppay[a]:=0;
  ttime[a]:=t;
  bfspay(a,t);
  writeln(ttime[b],' ',ppay[b]);
  close(input);
  close(output);
end.
