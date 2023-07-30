#!/usr/bin/env python3
"""
Pretty much inspired from <https://reliability.readthedocs.io/en/latest/How%20does%20Maximum%20Likelihood%20Estimation%20work.html>
"""
import sys
import functools
import numpy as np
from scipy import stats, optimize
import matplotlib.pyplot as plt


def L(alpha, beta, samples) -> float:

    return np.sum(
        np.fromiter(
            # from the samples perspective, `beta` is a constant, but if we want to minimize
            # wrt these parameters we cannot omit them
            (-np.log(beta) + np.log(np.square(beta) + np.square(sample - alpha)) for sample in samples),
            dtype=float,
        )
    )


def x(alpha, beta, theta):
    return beta * np.tan(theta) + alpha

def generate_sample(alpha, beta, count=100):
    thetas = stats.uniform.rvs(loc=-np.pi/2, scale=np.pi, size=count)

    return np.array(list(map(functools.partial(x, alpha, beta), thetas)))


def minimize_alpha_only():
    alpha_spaces = np.geomspace(0.1, 10, 100)

    thetas = stats.uniform.rvs(loc=-np.pi/2, scale=np.pi, size=100)

    samples = list(map(functools.partial(x, 1, 1), thetas))

    print(samples)

    Ls = []

    for alpha in alpha_spaces:
        Ls.append(L(alpha, 1, samples))

    def wrap_L(alpha, samples):
        return L(alpha, 1, samples)

    print(optimize.minimize(wrap_L, 0, args=(samples,)))


    plt.plot(alpha_spaces, Ls)
    plt.show()


def minimize_alpha_beta(samples_count):

    samples = generate_sample(5, 3)

    def wrap_L(params, samples):
        alpha, beta = params
        return L(alpha, beta, samples)

    print(optimize.minimize(wrap_L, [0.1, 0.1], args=(samples,)))

    alpha_space = np.linspace(0.1, 10, 100)
    beta_space  = np.linspace(0.1, 10, 100)

    LL = np.empty((len(alpha_space), len(beta_space)))

    for alpha_index, alpha in enumerate(alpha_space):
        for beta_index, beta in enumerate(beta_space):
            LL[alpha_index][beta_index] = L(alpha, beta, samples)

    LL_max = LL.min()
    index_max = np.where(LL == LL_max)

    alpha_best = alpha_space[index_max[0]][0]
    beta_best  = beta_space[index_max[1]][0]

    print(f"best fit: {alpha_best=} {beta_best=}")

    A, B = np.meshgrid(alpha_space, beta_space)

    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    ax.plot_surface(A, B, LL.transpose(),cmap="coolwarm",linewidth=1,antialiased=True,alpha=0.7,zorder=0)
    ax.scatter([alpha_best], [beta_best], [LL_max], color='k', zorder=1)
    ax.computed_zorder = False

    plt.show()


def main():
    count = int(sys.argv[1])
    minimize_alpha_beta(count)

if __name__ == '__main__':
    main()
