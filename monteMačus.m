(* ::Package:: *)

(* ::Input:: *)
(*kodaMonteC[n_]:=Module[{points,pointsInsideCircle,ratio,approxPi,plot},(*\[CapitalSHacek]tevilo naklju\[CHacek]nih to\[CHacek]k*)points=RandomPoint[Rectangle[{-1,-1},{1,1}],n];*)
(*(*Pre\[SHacek]tevanje to\[CHacek]k znotraj kroga*)pointsInsideCircle=Select[points,Norm[#]<=1&];*)
(*(*Razmerje to\[CHacek]k znotraj kroga in skupnega \[SHacek]tevila to\[CHacek]k*)ratio=Length[pointsInsideCircle]/n;*)
(*(*Pribli\[ZHacek]na vrednost \[Pi] kot decimalno \[SHacek]tevilo*)approxPi=N[4 ratio];*)
(*(*Graf z dodanim naslovom,legendo in obarvanimi to\[CHacek]kami*)plot=Graphics[{PointSize[Medium],Red,Point[Complement[points,pointsInsideCircle]],Green,Point[pointsInsideCircle],Blue,Circle[{0,0},1]},Axes->True,Frame->True,AspectRatio->1,PlotRange->{{-1,1},{-1,1}},ImageSize->Medium,Epilog->{Text["Monte Carlo simulacija za \[Pi]",{0,1.2}],Text[Style["Pribli\[ZHacek]an \[Pi]: "<>ToString[approxPi],Bold],{0,-1.3}],Inset[Framed["To\[CHacek]ke v krogu",Background->LightGreen],Scaled[{0.8,0.9}]],Inset[Framed["To\[CHacek]ke izven kroga",Background->LightRed],Scaled[{0.8,0.8}]]}];*)
(*(*Prikaz rezultata*)Print["Priblji\[ZHacek]ek vrednosti \[Pi]:",approxPi];*)
(*Return[plot];]*)
(**)
(*(*Primer klica funkcije s podanim \[SHacek]tevilom to\[CHacek]k (npr.1000)*)*)
(*kodaMonteC[1000]*)
(**)


(* ::Input:: *)
(**)
