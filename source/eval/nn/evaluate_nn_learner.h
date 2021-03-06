﻿// NN評価関数の学習で用いるインターフェイス

#ifndef _EVALUATE_NN_LEARNER_H_
#define _EVALUATE_NN_LEARNER_H_

#include "../../shogi.h"

#if defined(EVAL_LEARN) && defined(EVAL_NN)

#include "../../learn/learn.h"

namespace Eval {

namespace NN {

// 学習の初期化を行う
void InitializeTraining(double eta1, u64 eta1_epoch,
                        double eta2, u64 eta2_epoch, double eta3);

// ミニバッチのサンプル数を設定する
void SetBatchSize(u64 size);

// 学習率のスケールを設定する
void SetGlobalLearningRateScale(double scale);

// ハイパーパラメータなどのオプションを設定する
void SetOptions(const std::string& options);

// 学習用評価関数パラメータをファイルから読み直す
void RestoreParameters(const std::string& dir_name);

// 学習データを1サンプル追加する
void AddExample(Position& pos, Color rootColor,
                const Learner::PackedSfenValue& psv, double weight);

// 評価関数パラメータを更新する
void UpdateParameters(u64 epoch);

// 学習に問題が生じていないかチェックする
void CheckHealth();

}  // namespace NN

}  // namespace Eval

#endif  // defined(EVAL_LEARN) && defined(EVAL_NN)

#endif
