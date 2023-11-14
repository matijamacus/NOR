function calc_pi()
    % Določimo št. točk in radij kroga:
    St_tock = 10000;
    R = 1;

    % Določimo ocenjeno vrednost pi, napako in koordinate točk v krogu:
    [Ocena_Pi, error, koordinate_v_krogu] = area_pi(St_tock, R);

    disp(['Ocena π: ', num2str(Ocena_Pi)]);
    disp(['Napaka: ', num2str(error)]);
    disp('Koordinate točk znotraj kroga:');
    disp(koordinate_v_krogu);

    izris_grafa(St_tock, R);
end

function [Ocena_Pi, error, koordinate_v_krogu] = area_pi(nabor_tock, R)

    % Podamo začetno stanje:
    V_Krogu = 0;
    koordinate_v_krogu = zeros(nabor_tock, 2);

    % Anonimna funkcija, ki preverja ali je tocka T(x,y) na kroznici:
    Na_kroznici = @(x, y) x^2 + y^2 <= R^2;

    % Zapišemo for zanko:
    for i = 1:nabor_tock
        x = 2 * rand() - 1;
        y = 2 * rand() - 1;
        if Na_kroznici(x, y)
            V_Krogu = V_Krogu + 1;
            koordinate_v_krogu(i, :) = [x, y];
        end
    end
    Ocena_Pi = 4 * V_Krogu / nabor_tock;

    % Napako izrazimo kot absolutno vrednost:
    error = abs(Ocena_Pi - pi);
end


%Zapišemo funkcijo za izris grafa:

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
    title('Naključno generirane točke na krožnici z lokom');
    xlabel('X-os');
    ylabel('Y-os');
    legend('Znotraj krožnice', 'Zunaj krožnice', 'Krožnica');
end


function Plot_kroznice(r)
%Numerično določimo razdelitev kota za izris na 1000 kosov:
    kot = linspace(0, 2 * pi, 1000);
    x = r * cos(kot);
    y = r * sin(kot);
    plot(x, y, 'r', 'LineWidth', 2);
end
