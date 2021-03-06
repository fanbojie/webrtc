/*
 *  Copyright 2019 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef RTC_BASE_EXPERIMENTS_STABLE_TARGET_RATE_EXPERIMENT_H_
#define RTC_BASE_EXPERIMENTS_STABLE_TARGET_RATE_EXPERIMENT_H_

#include "api/transport/webrtc_key_value_config.h"
#include "rtc_base/experiments/field_trial_parser.h"

namespace webrtc {

class StableTargetRateExperiment {
 public:
  StableTargetRateExperiment(StableTargetRateExperiment&&);
  static StableTargetRateExperiment ParseFromFieldTrials();
  static StableTargetRateExperiment ParseFromKeyValueConfig(
      const WebRtcKeyValueConfig* const key_value_config);

  bool IsEnabled() const;
  absl::optional<double> GetVideoHysteresisFactor() const;
  absl::optional<double> GetScreenshareHysteresisFactor() const;

 private:
  explicit StableTargetRateExperiment(
      const WebRtcKeyValueConfig* const key_value_config,
      absl::optional<double> default_video_hysteresis,
      absl::optional<double> default_screenshare_hysteresis);

  FieldTrialParameter<bool> enabled_;
  FieldTrialOptional<double> video_hysteresis_factor_;
  FieldTrialOptional<double> screenshare_hysteresis_factor_;
};

}  // namespace webrtc

#endif  // RTC_BASE_EXPERIMENTS_STABLE_TARGET_RATE_EXPERIMENT_H_
