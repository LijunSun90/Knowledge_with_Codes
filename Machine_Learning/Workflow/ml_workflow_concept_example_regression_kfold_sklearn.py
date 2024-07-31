"""
1. For concept purpose: Illustrate the workflow for machine learning regression problem with k-fold cross validation.
2. The loss function is not customizable here.
Reference:
[1] https://scikit-learn.org/stable/modules/generated/sklearn.neural_network.MLPRegressor.html
"""

from sklearn.datasets import make_regression
from sklearn.neural_network import MLPRegressor
from sklearn.model_selection import train_test_split
from sklearn.model_selection import KFold


def machine_learning_regression_workflow():

    # ==================================================
    # Data.

    X, y = make_regression(n_samples=200, random_state=1)
    print("X:", X.shape)
    print("y:", y.shape)

    # ==================================================
    # Model.

    # Any integer for reproducibility purpose.
    random_state = 1

    # Maximum number of iterations. Hyperparameter (to be possibly tuned).
    max_iter = 500

    # This model optimizes the squared error using LBFGS or stochastic gradient descent.
    model = MLPRegressor(random_state=random_state, max_iter=max_iter)

    # ==================================================
    # K-fold cross validation.

    k_fold = 10
    kf = KFold(n_splits=k_fold)

    for fold_index, (train_index, test_index) in enumerate(kf.split(X)):

        # Data.
        X_train, y_train = X[train_index], y[train_index]
        X_test, y_test = X[test_index], y[test_index]

        # Train model.
        model = model.fit(X_train, y_train)

        # Performance.
        train_score = model.score(X_train, y_train)
        validation_score = model.score(X_test, y_test)
        print("Fold:", fold_index, ", Training:", train_score, ", Validation:", validation_score)

    pass


if __name__ == "__main__":

    machine_learning_regression_workflow()

    pass
