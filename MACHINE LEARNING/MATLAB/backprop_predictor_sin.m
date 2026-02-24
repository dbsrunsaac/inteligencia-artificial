clc, clear, close all;
% Patrones de aprendizaje y objetivos
P = linspace(-2, 2, 21);
T = 1 + sin(pi/4*P);


Q = length(P);
Nepocas = 300; % Número de epocas

% Valores iniciales
W1 = [-0.26; -0.41];
b1 = [-0.48; -0.13];
W2 = [0.09 -0.17];
b2 = [0.48];
alfa = 0.01;

for Epocas = 1 : Nepocas
    sum = 0;
    for q = 1:Q
        % Propagación de la entrada hacia la salida
        a1 = logsig(W1*P(:, q) + b1); % Capa oculta f logsin (función de activación sigmoidal)
        a2(q) = purelin(W2*a1 + b2); % Capa de salida F lineal (determina la red como regresion)
        
        % Retropropagación de sensibilidades
        e = T(q) - a2(q); % Error
        s2 = -2*(1)*e; % Retropropagación en la capa de salida
        s1 = diag(diag((1-a1)*a1'))*W2'*s2; % Retropropagación en la capa
        % Actualización de pesos sinapticos y polarizados
        W2 = W2 - alfa*s2*a1';
        b2 = b2 - alfa*s2;
        W1 = W1 - alfa*s1*P(:, q)';

        % Sumando el error cuadratico
        sum = e^2+sum;
    end
    % Error cuadratico medio
    % emedio(Ep)
end

subplot(2, 1, 1);
plot(P, a2, P, T);