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