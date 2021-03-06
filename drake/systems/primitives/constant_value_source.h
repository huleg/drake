#pragma once

#include <cstdint>
#include <memory>

#include "drake/systems/framework/context.h"
#include "drake/systems/framework/leaf_system.h"
#include "drake/systems/framework/system_output.h"
#include "drake/systems/framework/value.h"

namespace drake {
namespace systems {

/// A source block that always outputs a constant value.
/// @tparam T The vector element type, which must be a valid Eigen scalar.
/// @ingroup primitive_systems
///
/// This class uses Drake's `-inl.h` pattern.  When seeing linker errors from
/// this class, please refer to http://drake.mit.edu/cxx_inl.html.
///
/// Instantiated templates for the following kinds of T's are provided:
/// - double
///
/// They are already available to link against in the containing library.
template <typename T>
class ConstantValueSource : public LeafSystem<T> {
 public:
  /// @p value The constant value to emit.
  explicit ConstantValueSource(std::unique_ptr<AbstractValue> value);

  std::unique_ptr<SystemOutput<T>> AllocateOutput(
      const Context<T>& context) const override;

  void DoCalcOutput(const Context<T>& context,
                    SystemOutput<T>* output) const override;

 private:
  // TODO(david-german-tri): move source_value_ to the system's parameters.
  const std::unique_ptr<AbstractValue> source_value_;
};

}  // namespace systems
}  // namespace drake
