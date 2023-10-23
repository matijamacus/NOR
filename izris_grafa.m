
function izris_grafa(St_Tock, R)

    x = 2 * rand(St_Tock, 1) - 1;
    y = 2 * rand(St_Tock, 1) - 1;
    razdalja = sqrt(x.^2 + y.^2);

    tocke_v = razdalja <= R;
    tocke_izven = razdalja > R;
    
    % Določimo barvo in obliko točk na grafu
    scatter(x(tocke_v), y(tocke_v), 50, 'blue', 'o', 'filled');
    hold on;
    scatter(x(tocke_izven), y(tocke_izven), 50, 'r', 'o');
    
    Plot_kroznice(R);
    axis equal;
   
end
